const decoder = new TextDecoder();

export function construct(memoryView: ArrayBuffer): string {
    return decoder.decode(memoryView);
}
